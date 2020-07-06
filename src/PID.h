#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  /**
   * Calculate the cumulative PID error.
   * @output The cumulative PID error
   */
  double CumulativeError();

  /**
   * Calculate the next steer value.
   * @output The next steer value
   */
  double GetSteerValue();

  void ShowResult();

  unsigned int ticks;
 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  double cumulative_error;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H