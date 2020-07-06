#include<iostream>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;
  this->p_error_prev = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  this->p_error = cte;
  this->d_error = this->p_error - this->p_error_prev;
  this->p_error_prev = this->p_error;
  this->i_error += this->p_error;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // std::cout << " p_error: " << this->p_error
  //           << " i_error: " << this->i_error
  //           << " d_error: " << this->d_error << std::endl;
  double total_error = (this->Kp * this->p_error) +
                       (this->Ki * this->i_error) +
                       (this->Kd * this->d_error);
  return total_error;  // TODO: Add your total error calc here!
}