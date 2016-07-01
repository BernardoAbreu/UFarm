#!/usr/bin/env python

"""
Spyder Editor

This is a temporary script file.
"""

import time
from datetime import datetime 

###############################################################################
#from RF24 import *
#import RPi.GPIO as GPIO
###############################################################################

###############################################################################
#Info

# 0 - Valve
# 1 - Duration of time open   ( in minutes )
# 2 - Duration of time closed ( in minutes )
# 4 - Last time accessed      - (Hour, Minute)
# 5 - Reset Time (Optional)   - ( (Hour, Minute), Initial State )
class Info:
    
    def __init__(self,valve,t_open,t_closed, reset, check):
        self.valve = valve
        self.open = t_open
        self.closed = t_closed
        self.last_time = datetime.now()
        self.reset = reset
        self.check_time = check
        self.last_check = datetime.now()
        
        
##############################################################################    
    
    
    
##############################################################################
#Valve

class Valve:
    

    def __init__(self, number, state = False):
        self.valve_number = number
        self.state = state
        self.code = 100 + number
        self.valveState = None
        
    
    def getNumber(self):
        return self.valve_number
        
        
    def setReadPipe(self, readPipe):
        self.readPipe = readPipe
        
    
    def setWritePipe(self, writePipe):
        self.writePipe = writePipe
        
    
    def setState(self, state):
        self.state = state
        
    
    def getState(self):
        return self.state
        
        
    def setValveState(self,state):
        self.valveState = state
        
        
    def getValveState(self):
        return self.valveState
        

    def sendState(self, state):
        #radio.stopListening()

        valveCode = self.code*10 + int(state)
        # Take the time, and send it.  This will block until complete
        print 'Now sending code ', valveCode, ' ... ',
        #ok = radio.write(valve_code)

        #if not ok:
			#print "failed.\n"

        # Now, continue listening
        #radio.startListening()

        # Wait here until we get a response, or timeout
        #started_waiting_at = millis()
        #timeout = False
        #while (not radio.available()) and (not timeout):
            #if (millis() - started_waiting_at) > 1000:
                #timeout = True

        # Describe the results
        #if timeout:
            #print 'failed, response timed out.'
        #else:
            # Grab the response, compare, and send to debugging spew
            #len = radio.getDynamicPayloadSize()
            #receive_payload = radio.read(len)

            # Spew it
            #print 'got response size=', len, ' value="', receive_payload, '"'
        self.setState(state)
        self.setValveState(state)
        time.sleep(0.1)
        
        
    def readState(self):
        msg = 0
        state = self.getValveState()
#        if radio.available():
#            while radio.available():
#                len = radio.getDynamicPayloadSize()
#                receive_payload = radio.read(len)
#                print('Got payload size={} value="{}"'.format(len, receive_payload.decode('utf-8')))
#        
#                msg = int(receive_payload.decode('utf-8'))
#                state = bool(msg%10)
#        
#                # First, stop listening so we can talk
#                radio.stopListening()
#        
#                # Send the final one back.
#                radio.write(receive_payload)
#                print('Sent response.')
#        
#                # Now, resume listening so we catch the next packets.
#                radio.startListening()

        self.setValveState(self.getState())
        return self.getValveState()

        
    def checkState(self):
        self.readState()
        return self.getValveState() == self.getState()


##############################################################################
        

##############################################################################
#Schedule
#
class Schedule:
    outfile = 'schedule_info.txt'
    
    def __init__(self):
        self.valves = {}
        self.last_minute = datetime.now().time().minute-1
        
    
    def addValve(self, valve, t_open, t_closed, reset = (-1,-1,False), 
                 check = 60):
        #self.valves[valve.getNumber()] = {'valve' : valve,
                                        #'open' : t_open,
                                        #'closed' : t_closed,
                                        #'last_time' : datetime.now().time(),
                                        #'reset' : reset}
        self.valves[valve.getNumber()] = Info(valve, t_open, t_closed, reset,
                    check)


    def removeValve(self, valve):
        del self.valves[valve]


    def monitorValves(self):
        time = datetime.now()

        if self.last_minute != time.minute:
            checknow = False
            
            for key, v in self.valves.iteritems():
                #passed_time = (time.minute + time.hour*60) - \
                                #(v.last_time.hour*60 + v.last_time.minute)
                
                passed_time = time - v.last_time
                passed_check = time - v.last_check
                #p_c_time = passed_check.days*24*60 + passed_check.seconds/60.0                            
                
                                
                if v.reset[:2] == (time.hour, time.minute):
                    v.valve.setState(v.reset[2])
                    v.last_time = time

                    with open(self.outfile, "a") as myfile:
                        myfile.write('Valve {} {}'.format(v.valve.getNumber(),\
                        'open' if v.valve.getState() else 'closed'))
                    
                    print 'valve', v.valve.getNumber(), \
                    'open' if v.valve.getState() else 'closed'
                    
                else:
                    if passed_check.seconds/60.0 >= v.check_time:
                    #if p_c_time >= v.check_time:
                        v.last_check = time
                        print 'Checking valve ' + str(v.valve.getNumber())
                        outstr = 'Checking valve ' + \
                                str( v.valve.getNumber() ) + '\n'
                                
                        state_ok = v.valve.readState()
                        
                        if state_ok:
                            outstr += 'Valve {} ok: {}'.format(
                                    v.valve.getNumber(),
                                    'open' if v.valve.getState() else 'closed')
                            
                            print 'valve', v.valve.getNumber(), 'ok:', \
                            'open' if v.valve.getState() else 'closed'
                        else:
                            outstr += 'Error on valve {}: Currently {}. Should \
                            be {}'.format(v.valve.getNumber(),
                            'open' if v.valve.getValveState() else 'closed',
                            'open'if v.valve.getState() else 'closed')
                            
                            print 'Error on valve', v.valve.getNumber(), \
                            '. Currently', \
                            'open' if v.valve.getValveState() else 'closed', \
                            '. Should be', \
                            'open'if v.valve.getState() else 'closed'
                        
                        with open(self.outfile, "a") as myfile:
                            myfile.write(outstr)
                            
                    if v.valve.getState():
                        if passed_time.seconds/60.0 >= v.open:
                        #if passed_time >= v.open:
                            #v.valves.sendState = False
                            v.valve.sendState(False)
                            v.last_time = time
                            
                            if not checknow:
                                with open(self.outfile, "a") as myfile:
                                    myfile.write('\n'+str(time)+'\n')
                                print time
                                checknow = True

                            print 'valve', v.valve.getNumber(), \
                                'open' if v.valve.getState() else 'closed'
                                
                            with open(self.outfile, "a") as myfile:
                                myfile.write('Valve {} {}\n'.format(
                                v.valve.getNumber(),
                                'open' if v.valve.getState() else 'closed'))
                    else:                  
                        if passed_time.seconds/60.0 >= v.closed:
                        #if passed_time >= v.closed:
                            v.valve.sendState(True)
                            v.last_time = time
                           
                            if not checknow:
                                with open(self.outfile, "a") as myfile:
                                    myfile.write('\n'+str(time)+'\n')
                                print time
                                checknow = True
                                
                            print 'valve', v.valve.getNumber(), \
                                'open' if v.valve.getState() else 'closed'
                                
                            with open(self.outfile, "a") as myfile:
                                myfile.write('Valve {} {}\n'.format(
                                v.valve.getNumber(),
                                'open' if v.valve.getState() else 'closed'))
    
        self.last_minute = time.minute
        time.sleep(50)

    def setOutFile(self, out):
        self.outfile = out
        
        
    def getOutFile(self):
        return self.outfile



###############################################################################
#irq_gpio_pin = None
#radio = RF24(22, 0);
#millis = lambda: int(round(time.time() * 1000))


#def setup():
#	radio.begin()
#	radio.setRetries(5,15)
#	radio.printDetails()
#
#    print 'Role: Control Arduino, starting transmission'
#    radio.openWritingPipe(pipes[0])
#    radio.openReadingPipe(1,pipes[1])

#def send_code(code):
#	    # The payload will always be the same, what will change is how much of it we send.
#
#        # First, stop listening so we can talk.
#        radio.stopListening()
#
#        # Take the time, and send it.  This will block until complete
#        print 'Now sending code ', code, ' ... ',
#        ok = radio.write(code)
#       	
#		if not ok:
#			print "failed.\n"
#
#        # Now, continue listening
#        radio.startListening()
#
#        # Wait here until we get a response, or timeout
#        started_waiting_at = millis()
#        timeout = False
#        while (not radio.available()) and (not timeout):
#            if (millis() - started_waiting_at) > 1000:
#                timeout = True
#
#        # Describe the results
#        if timeout:
#            print 'failed, response timed out.'
#        else:
#            # Grab the response, compare, and send to debugging spew
#            len = radio.getDynamicPayloadSize()
#            receive_payload = radio.read(len)
#
#			# Spew it
#			print 'got response size=', len, ' value="', receive_payload, '"'
#
#        time.sleep(0.1)


#def changeRadioRole(inp_role, pipe_rpi, pipe_ard):
#    if inp_role == '0':
#        print('Role: Pong Back, awaiting transmission')
#        if irq_gpio_pin is not None:
#            # set up callback for irq pin
#            GPIO.setmode(GPIO.BCM)
#            GPIO.setup(irq_gpio_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
#            GPIO.add_event_detect(irq_gpio_pin, GPIO.FALLING, callback=try_read_data)
#    
#        radio.openWritingPipe(pipes_ard)
#        radio.openReadingPipe(1,pipes_rpi)
#        radio.startListening()
#    else:
#        print('Role: Ping Out, starting transmission')
#        radio.openWritingPipe(pipes_rpi)
#        radio.openReadingPipe(1,pipes_ard)
###############################################################################


    
def main():

    sch = Schedule()
        
    sch.addValve( Valve(0), 1, 2, (16,51,True) )
    sch.addValve( Valve(1), 2, 1 )

    sch.setOutFile('info.txt')
    
    with open(sch.getOutFile(), "a") as myfile:
        myfile.write('Started running:\n{}\n'.format(datetime.now()))

    print 'Started running:\n{}\n'.format(datetime.now())
    
    while True:
        sch.monitorValves()
        


main()