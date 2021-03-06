/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/
#pragma once

#include "AbstractResqmlDataObjectTest.h"
#include <iostream>
#include <vector>
#include <map>

namespace COMMON_NS {
	class EpcDocument;
}

namespace resqml2_0_1test {
	class ActivityTemplateTest : public AbstractResqmlDataObjectTest {
	public:
		ActivityTemplateTest(const std::string & epcDocPath, const std::string & uuid, const std::string & title);
		ActivityTemplateTest(COMMON_NS::EpcDocument * epcDoc, const std::string & uuid, const std::string & title);
	protected:
		struct ParameterTest {
			std::string title;
			bool isInput;
			bool isOutput;
			int minOccurs;
			int maxOccurs;
		};

		std::map<std::string, ParameterTest> parameterMap;

		void initEpcDocHandler();
		void readEpcDocHandler();
	};
}

