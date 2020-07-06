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
  this->ticks = 0;
  this->cumulative_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  double p_error_prev = this->p_error;
  this->p_error = cte;
  this->i_error = this->i_error + this->p_error;
  this->d_error = this->p_error - p_error_prev;
  this->cumulative_error += TotalError();
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return this->p_error + this->i_error + this->d_error;
}

double PID::GetSteerValue() {
  double steer_value = -((this->Kp * this->p_error) +
                         (this->Ki * this->i_error) +
                         (this->Kd * this->d_error));
  return steer_value;
}

void PID::ShowResult() {
  std::cout << "(" << this->Kp << ", " << this->Ki << ", " << this->Kd << ") "
            << "Cumulative ERROR: " << this->cumulative_error << std::endl;
}