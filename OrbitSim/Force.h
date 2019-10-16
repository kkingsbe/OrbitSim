#ifndef FORCE_H
#define FORCE_H
class Force
{
	private:
		double x = 0.0;
		double y = 0.0;
	public:
		double getMagnitude();
		double getXComponent();
		double getYComponent();
		double getTheta();

		void setMagnitude(double magnitude);
		void setXComponent(double x);
		void setYComponent(double y);
		void setTheta(double theta);
};
#endif
