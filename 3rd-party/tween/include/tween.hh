

#ifndef _TWEEN_H_
#define _TWEEN_H_

#include "easing.hh"
#include "tweenData.hh"


				enum ETWEEN_STATE
				{
					ETWEEN_STATE_PLAYING,
					ETWEEN_STATE_PAUSED,
					ETWEEN_STATE_STOPPED,
					ETWEEN_STATE_FINISHED,
				};
				

				class Tween {
				public:
					Tween();
					void SetTweenData(TweenData& data);
					void Update();
					void Play();
					void Pause();
					void Stop();
					void SetNum(float);
					bool Finished();
					void Reset();
					ETWEEN_STATE GetState();
					double GetTimeInMillis();

					float num;
					float percent;

				private:
					double prev_; 				// previous tick time
					double elapsed_;			// elapsed 
					TweenData data_;
					ETWEEN_STATE state_;
				}; //end of class Tween 
		
#endif //