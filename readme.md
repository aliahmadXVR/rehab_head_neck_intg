![Version](https://img.shields.io/badge/MRR-XAVOR-yellow)
# Rehab Robot Head & Neck Integration


## Overview

### How to Run PAN-TILT For Testing From PC

1. Make sure roscore is running on Testing PC
2. Make sure the ESP on Hardware side is connected to same network and the IP of testing PC is set properly on ESP end. 
3. Run the following node on the testing PC:
   
   ```rosrun rosserial_python serial_node.py tcp 11411```
4. Run the following node for publishing the pan and tilt sample message to respective topic: 
   
   ```rosrun rehab_head_neck_intg pan_tilt_int```
5. Type '1' as input to publish the messages to the respective topics each time you write '1'.
   

    



### Published Topics

1. ```/tilt_angles ```

    Topic Type: 
    
    std_msgs::Int32MultiArray
    

2. ```/pan_angles```
   
    Topic Type: 
    
    std_msgs::Int32MultiArray



<br></br>

## Contact
**Author:** Ali Ahmad  <br/>
**Designation:** Senior Robotics Engineer <br/>
**Email:** ali.ahmad@xavor.com <br/>