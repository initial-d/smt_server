.PHONY: all decoder clean

all:
	mkdir -p bin/include
	mkdir -p bin/lib
	cp src/*.h bin/include/
	g++ -g -c -I dependency/simple_log/include/ -I dependency/json-cpp/include/ -I src src/http_parser.cpp -o bin/http_parser.o
	g++ -g -c -I dependency/simple_log/include/ -I dependency/json-cpp/include/ -I src src/http_server.cpp -o bin/http_server.o
	g++ -g -c -I dependency/simple_log/include/ -I dependency/json-cpp/include/ -I src src/epoll_socket.cpp -o bin/epoll_socket.o
	ar -rcs libsimpleserver.a bin/*.o
	mv libsimpleserver.a bin/lib/
	rm -rf bin/*.o
#decoder: decoder/Config.cpp decoder/Global.cpp decoder/Interface.cpp decoder/Main.cpp decoder/MemManager.cpp decoder/Model.cpp decoder/OurChart.cpp decoder/OurDecoder.cpp decoder/OurDecoder_Phrase_ITG.cpp decoder/OurDecoder_Phrase_Stack.cpp decoder/OurDecoder_SCFG.cpp decoder/OurDecoder_SCFG_CSFM.cpp decoder/OurDecoder_SCFG_Tree.cpp decoder/OurInputSentence.cpp decoder/OurLM.cpp decoder/OurSharedStructure.cpp decoder/OurTrainer.cpp decoder/OurTree.cpp decoder/TrainingAndDecoding.cpp decoder/Utilities.cpp decoder/DataCheck.cpp decoder/OurDecoder_Skeleton.cpp
#	g++   -g -I dependency/simple_log/include/ -I dependency/json-cpp/include/ -I bin/include decoder/Config.cpp decoder/Global.cpp decoder/Interface.cpp decoder/Main.cpp decoder/MemManager.cpp decoder/Model.cpp decoder/OurChart.cpp decoder/OurDecoder.cpp decoder/OurDecoder_Phrase_ITG.cpp decoder/OurDecoder_Phrase_Stack.cpp decoder/OurDecoder_SCFG.cpp decoder/OurDecoder_SCFG_CSFM.cpp decoder/OurDecoder_SCFG_Tree.cpp decoder/OurInputSentence.cpp decoder/OurLM.cpp decoder/OurSharedStructure.cpp decoder/OurTrainer.cpp decoder/OurTree.cpp decoder/TrainingAndDecoding.cpp decoder/Utilities.cpp decoder/DataCheck.cpp decoder/OurDecoder_Skeleton.cpp  dependency/simple_log/lib/libsimplelog.a bin/lib/libsimpleserver.a dependency/json-cpp/lib/libjson_libmt.a -lcurl -lpthread -ldl  -o bin/decoder
	
clean:
	rm -rf bin/*

