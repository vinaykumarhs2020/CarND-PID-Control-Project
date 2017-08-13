#include "PID.h"
#include <iostream>

#define _DEBUG

// using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  // Assign initial K[idp] constants
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  // Initialize all errors to zero
  this->p_error = this->i_error = this->d_error = 0;
}

void PID::UpdateError(double cte) {
  // Update errors:
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;

#ifdef _DEBUG
  std::cout << "Kp: " << Kp << " Ki: " << Ki << " Kd: " << Kd << std::endl;
  std::cout << "P_error: " << p_error << " I_error: " << i_error << " D_error: " << d_error << std::endl;
#endif
}

double PID::TotalError() {
  return -1.0 * (Kp*p_error + Ki*i_error + Kd*d_error);
}
