/* NiuTrans - SMT platform
 * Copyright (C) 2011, NEU-NLPLab (http://www.nlplab.com/). All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

/*
 * $Id:
 * Main.cpp
 *
 * $Version:
 * 1.1.0
 *
 * $Created by:
 * Tong Xiao (email: xiaotong@mail.neu.edu.cn)
 *
 * $Last Modified by:
 * Hao Zhang (email: zhanghao1216@gmail.com); June 22th, 2011; add option "-decoding"
 * Tong Xiao (email: xiaotong@mail.neu.edu.cn); June 15th, 2013; add option "-eval"
 *
 */

#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include "simple_log.h"
#include "http_server.h"

#include <stdio.h>
#include <string.h>

#include "Global.h"
#include "OurLM.h"
#include "OurDecoder_Phrase_ITG.h"
#include "OurDecoder_SCFG.h"
#include "OurTrainer.h"
#include "TrainingAndDecoding.h"
#include "Interface.h"

using namespace smt;


Model * model;
OurSystem * s;

void decoder(Request &request, Json::Value &root) 
{
        std::string sen = request.get_param("sentence");

	for(int i = 0; i < sen.size(); i++ ) {
		if(sen[i] == '_') {
			sen[i] = ' ';
		}
	}

        SetUseF1Criterion( false );
        SetNormalizationLabel( true );

        char* ans = s->Decoding( sen.c_str(), model, PHRASE_BASED, false);
        root["sentence"] = ans;

    	return ;
}

int main(int argc, char **args) {
	if (argc < 2) {
        	LOG_ERROR("usage: ./http_server_test [port]");
        	return -1;
    	}
    	void* hInsDll = GetLmFunc();
    	if( hInsDll == NULL )
   	{
        	fprintf( stderr, "[ERROR]: Language Model Library not existed!\n" );
        	return 1;
    	}
	const char* temp[13] = {"../bin/NiuTrans.Decoder", "-decoding ", "", "-config", "./NiuTrans.phrase.user.config", "-output", "", "-outputoov", "1", "-nbest", "1", "-nthread", "4"};
        ConfigManager.Create(13, temp);
	s = new OurSystem();
	model = s->build_model();
        HttpServer http_server;

        http_server.add_mapping("/decoder", decoder);

        int port = atoi(args[1]);
        int backlog = 1000;
        int max_events = 100000;
	

        http_server.start(port, backlog, max_events);

        delete s;
        delete model;
        return 0;
}
