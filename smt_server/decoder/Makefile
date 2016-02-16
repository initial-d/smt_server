CXXFLAGS = -O2

OBJS = Config.o Global.o Interface.o Main.o MemManager.o Model.o OurChart.o OurDecoder.o OurDecoder_Phrase_ITG.o OurDecoder_Phrase_Stack.o OurDecoder_SCFG.o OurDecoder_SCFG_CSFM.o OurDecoder_SCFG_Tree.o OurInputSentence.o OurLM.o OurSharedStructure.o OurTrainer.o OurTree.o TrainingAndDecoding.o Utilities.o DataCheck.o OurDecoder_Skeleton.o
LIBS=../dependency/simple_log/lib/libsimplelog.a ../bin/lib/libsimpleserver.a ../dependency/json-cpp/lib/libjson_libmt.a -lpthread -ldl -lcurl

# smt platform
NiuTrans.Decoder: $(OBJS)
	g++ -g -o ../bin/$@ $^ $(LIBS)

$(OBJS): %.o:%.cpp
	g++ $(CXXFLAGS) -g -o $@ -c $<  -I ../dependency/simple_log/include/ -I ../dependency/json-cpp/include/ -I ../bin/include

.PHONY: clean

clean:
	-rm $(OBJS) ../bin/NiuTrans.Decoder
