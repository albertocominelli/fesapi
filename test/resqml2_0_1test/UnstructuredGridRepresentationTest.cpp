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
#include "UnstructuredGridRepresentationTest.h"

using namespace std;
using namespace COMMON_NS;
using namespace resqml2_0_1test;

const char* UnstructuredGridRepresentationTest::defaultUuid = "d084eef4-137a-423f-a41c-8064868bcfa0";
const char* UnstructuredGridRepresentationTest::defaultTitle = "Unstructured Grid Representation";

UnstructuredGridRepresentationTest::UnstructuredGridRepresentationTest(const string & epcDocPath, const string & uuid, const string & title, const ULONG64 & xyzPointCountOfAllPatches, double * xyzPointsOfAllPatchesInGlobalCrs)
	: AbstractGridRepresentationTest(epcDocPath, uuid, title, xyzPointCountOfAllPatches, xyzPointsOfAllPatchesInGlobalCrs) {
}

UnstructuredGridRepresentationTest::UnstructuredGridRepresentationTest(EpcDocument * epcDoc, const string & uuid, const string & title, const ULONG64 & xyzPointCountOfAllPatches, double * xyzPointsOfAllPatchesInGlobalCrs)
	: AbstractGridRepresentationTest(epcDoc, uuid, title, xyzPointCountOfAllPatches, xyzPointsOfAllPatchesInGlobalCrs) {
}

