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

#include "common/AbstractObject.h"

namespace RESQML2_NS
{
	class DLL_IMPORT_OR_EXPORT AbstractProperty: public COMMON_NS::AbstractObject
	{
	public:

		/**
		* Only to be used in partial transfer context
		*/
		AbstractProperty(gsoap_resqml2_0_1::eml20__DataObjectReference* partialObject) : COMMON_NS::AbstractObject(partialObject) {}

		/**
		* Default constructor
		* Set the relationship with an AbstractRepresentation and a local property type.
		*/
		AbstractProperty(): local3dCrs(nullptr) {}

		/**
		* Creates an instance of this class by wrapping a gsoap instance.
		*/
		AbstractProperty(gsoap_resqml2_0_1::resqml2__AbstractProperty* fromGsoap) : COMMON_NS::AbstractObject(fromGsoap), local3dCrs(nullptr) {}

		/**
		* Destructor does nothing since the memory is managed by the gsoap context.
		*/
		virtual ~AbstractProperty() {}

		/**
		 * Set the representation which is associated to the current property.
		 */
		void setRepresentation(class AbstractRepresentation * rep);

		/**
		* @return	null pointer if no representation is associated to this property. Otherwise return the data object reference of the associated representation.
		*/
		gsoap_resqml2_0_1::eml20__DataObjectReference* getRepresentationDor() const;

		/**
		* Getter for the representation which supports this instance values.
		*/
		class AbstractRepresentation* getRepresentation() const;

		/*
		* Getter for the uuid of the representation which is described by this property
		*/
		std::string getRepresentationUuid() const;

		/*
		* Getter for the title of the representation which is described by this property
		*/
		std::string getRepresentationTitle() const;

		/*
		* Getter for the content type of the representation which is described by this property
		*/
		std::string getRepresentationContentType() const;

		/**
		 * Set the representation which is associated to the current property.
		 */
		void setTimeSeries(class TimeSeries * ts);

		/**
		* Getter for the time series which is associated to this property.
		*/
		TimeSeries* getTimeSeries() const;

		/**
		* @return	null pointer if no time series is associated to this property. Otherwise return the data object reference of the associated time series.
		*/
		gsoap_resqml2_0_1::eml20__DataObjectReference* getTimeSeriesDor() const;

		/*
		* Getter for the uuid of the time series which is associated to this property.
		*/
		std::string getTimeSeriesUuid() const;

		/*
		* Getter for the uuid of the time series which is associated to this property.
		*/
		std::string getTimeSeriesTitle() const;

		/**
		* Set the timestamp of this property by means of an index in a time series
		*
		* @param[in]	 timeIndex	The index of the timestamp of the property in the time series.
		* @param[in]	 ts			The time series which contains the timestamp of this property.
		*/
		void setTimeIndex(const unsigned int & timeIndex, class TimeSeries * ts);

		/**
		* Set the timestep of this property
		*/
		void setTimeStep(const unsigned int & timeStep);

		/**
		* Get the timestamp of this property
		* @return maximum value of unsigned int is returned if no timestamp is allowed.
		*/
		time_t getTimestamp() const;

		/**
		* Get the time index of this property in its assocaited time series
		*/
		unsigned int getTimeIndex() const;

		/**
		* Set the Hdf Proxy where the numerical values are stored.
		*/
		void setHdfProxy(COMMON_NS::AbstractHdfProxy * proxy);

		/**
		* Getter for the hdf proxy which stores this instance values.
		*/
		COMMON_NS::AbstractHdfProxy* getHdfProxy() const;

		/*
		 * Getter for the uuid of the hdf proxy which is used for storing the numerical values of this property.
		 * An empty string is returned if no hd fproxy is used for storing the numerical values.
		 */
		std::string getHdfProxyUuid() const;

		/**
		* Getter (in read only mode) of the element count per property value.
		* If the property is a scalar one then it should be one.
		* If it is a vectorial one, the it should be more than one.
		* It is not possible to have some tensor property values (more dimension than a vector).
		*/
		unsigned int getElementCountPerValue() const;

		/**
		* Get the kind of elments the property values are attached to.
		*/
		gsoap_resqml2_0_1::resqml2__IndexableElements getAttachmentKind() const;

		/**
		* Indicates if the property kind attached to this property is either from the standard catalog of Energistics or from a local property kind.
		*/
		bool isAssociatedToOneStandardEnergisticsPropertyKind() const;

		//*********************************************
		//****** PROP KIND ****************************
		//*********************************************

		/**
		* Get the title of the property kind of this property
		*/
		std::string getPropertyKindDescription() const;

		/**
		* Get the title of the property kind of this property
		*/
		std::string getPropertyKindAsString() const;

		/**
		* Get the title of the parent of the property kind.
		*/
		std::string getPropertyKindParentAsString() const;

		/**
		* Getter for the energistics property kind which is associated to this intance.
		*/
		gsoap_resqml2_0_1::resqml2__ResqmlPropertyKind getEnergisticsPropertyKind() const;

		/**
		* Set the property kind of the property to a local one.
		*/
		void setLocalPropertyKind(class PropertyKind* propKind);

		/**
		* @return	null pointer if no local property kind is associated to this property. Otherwise return the data object reference of the associated local property kind.
		*/
		gsoap_resqml2_0_1::eml20__DataObjectReference* getLocalPropertyKindDor() const;

		/**
		* Get the uuid of the local property kind which is associated to this property.
		*/
		std::string getLocalPropertyKindUuid() const;

		/**
		* Get the title of the local property kind which is associated to this property.
		*/
		std::string getLocalPropertyKindTitle() const;

		/**
		* Getter for the local property kind which is associated to this instance.
		* If nullptr is returned then it means this instance is associated to an energistics standard property kind.
		*/
		class PropertyKind* getLocalPropertyKind() const;

		/**
		* Check if the associated local property kind is allowed for this property.
		*/
		virtual bool validatePropertyKindAssociation(class PropertyKind* pk) = 0;

		/**
		* Check if the associated standard property kind is allowed for this property.
		*/
		virtual bool validatePropertyKindAssociation(const gsoap_resqml2_0_1::resqml2__ResqmlPropertyKind & pk) = 0;

	protected:

		void setXmlRepresentation(class AbstractRepresentation * rep);
		void setXmlTimeSeries(TimeSeries * ts);
		void setXmlLocalPropertyKind(class PropertyKind* propKind);

		virtual std::vector<epc::Relationship> getAllEpcRelationships() const;
		virtual void importRelationshipSetFromEpc(COMMON_NS::EpcDocument * epcDoc);

		class AbstractLocal3dCrs *		local3dCrs;			/// The used local 3D CRS in case the property values need one.
	};
}

