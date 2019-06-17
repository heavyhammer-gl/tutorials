
#ifndef _TWEENDATA_H_
#define _TWEENDATA_H_


                class TweenData{
                public:
                    TweenData();
                    void SetDuration(double duration);
                    void SetDelay(double delay);
                    void SetFrom(double from);
                    void SetTo(double to);
                    void SetIsLoop(bool isLoop);
                    void SetInterpolator(float (* ease)(float, float, float, float));
                    double GetDuration();
                    double GetDelay();
                    double GetFrom();
                    double GetTo();
                    bool IsLoop();
                    double GetInterpolatedValue(double tick);

                private:
					double duration_; 
					float from_; 
					float to_;
					double delay_; 
					bool loop_;
					float (* ease_)(float, float, float, float);
				};
           

#endif //