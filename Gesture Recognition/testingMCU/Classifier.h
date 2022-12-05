#pragma once
#include <stdarg.h>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class Classifier {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[4] = { 0 };
                        // tree #1
                        if (x[4] <= -1.3948387503623962) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[8] <= -2.799999952316284) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #2
                        if (x[3] <= 3.6449998915195465) {
                            votes[0] += 1;
                        }

                        else {
                            votes[2] += 1;
                        }

                        // tree #3
                        if (x[21] <= 1.3475278108380735) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[11] <= 10.234999895095825) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[17] <= 7.629999756813049) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        // tree #4
                        if (x[16] <= -10.335000038146973) {
                            votes[2] += 1;
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #5
                        if (x[15] <= 13.0) {
                            votes[0] += 1;
                        }

                        else {
                            votes[3] += 1;
                        }

                        // tree #6
                        if (x[19] <= 15.274999618530273) {
                            votes[2] += 1;
                        }

                        else {
                            if (x[9] <= 10.56000018119812) {
                                votes[1] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        // tree #7
                        if (x[11] <= 9.890000104904175) {
                            votes[1] += 1;
                        }

                        else {
                            if (x[17] <= 15.274999618530273) {
                                votes[2] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        // tree #8
                        if (x[16] <= -15.434999942779541) {
                            if (x[22] <= 18.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            votes[3] += 1;
                        }

                        // tree #9
                        if (x[7] <= 15.5) {
                            if (x[19] <= 19.364999771118164) {
                                votes[3] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[5] <= 1.1761619495227933) {
                                votes[0] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // tree #10
                        if (x[0] <= -3.749999910593033) {
                            if (x[14] <= 16.5) {
                                votes[1] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 4; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "rest";
                            case 1:
                            return "vertical";
                            case 2:
                            return "horizontal";
                            case 3:
                            return "circle";
                            default:
                            return "Frank we have a problem!";
                        }
                    }

                protected:
                };
            }
        }
    }
