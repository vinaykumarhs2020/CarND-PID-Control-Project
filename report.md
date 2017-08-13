# PID Controller Project
---

### Implementation
This project implements a PID (proportional-integral-derivative) controller to control the steering angle and throttle for a car in a simulator.

### Hyperparameter selection for steering value
Three main parameters in a PID controller are Kp, Ki and Kd. They control how to handle proportional, integral and derivative errors respectively.

A large Kp steering parameter resulted in a lot of oscillations in the steering angle. `cte` is used as a proportional error term and Kp values from 0.001 to 10 were independently tested. A value of __0.04__ was chosen empirically.

Kd had an interesting effect on the steering angle. Smaller values (0.001 - ~2.5) didn't show much impact of d_error (`cte - old_cte`) term. The car had a lot of oscillations. When Kd was increased to large numbers (>10) the car front tires reacted for every small error in d_error and were trying to correct every time. A value of __6.5__ was found to be working better.

Initially, my Ki term was 0. This was because I was using d_error as total accumulated error. Increasing this number was a disaster and drove the car of the tracks most of the times. Later, I used a simple circular buffer (defined in `src/CircBuff.h`) to capture the last __10__ errors. This helped a lot! Vehicle drove much smoothly in turns. I chose __Ki = 0.01__ was chosen empirically while range of Ki = [0.00001, 10] was tried to find the best performance.

### Throttle Value
For all the initial tests, I used a default `throttle=0.3` value and it was working fine. Once I had a pretty good steering angle control, I used `abs(steering_value)` as error measure to control throttle value. On a high level, whenever car needs to steer a lot, throttle is reduced and throttle is maintained at 0.9 otherwise.

```
throttle = 0.9 + throttle_pid.TotalError();
```

This line calculates the throttle value. Hyperparameters `Kp = 0.15, Ki = 0.18, Kd = 0.0` were chosen empirically.

With two PID controllers, the car was able to reach up to ~75mph on the straight stretch of the road slow down to ~35mph to carefully steer the steep turns.
