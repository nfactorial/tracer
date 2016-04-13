//
// Copyright 2016 nfactorial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//


#ifndef SAMPLE_CONTAINER_HEADER_INCLUDED
#define SAMPLE_CONTAINER_HEADER_INCLUDED


// -----------------------------------------------------------------------------------

#include <cstddef>
#include <cassert>

#include "image_sample.h"


// -----------------------------------------------------------------------------------

namespace tracer {
    //! \brief  Container for samples generated using an ISampler interface.
    //!
    //! This class must be inherited, where the derived object should supply the
    //! capacity and buffer where the samples are to be stored.
    class SampleContainer {
    public:
        ~SampleContainer();

        void clear();
        bool addSample(ImageSample &sample);

        size_t size() const;
        size_t capacity() const;

        const ImageSample& operator[](size_t index) const;

    protected:
        SampleContainer(size_t capacity, ImageSample *buffer);

    private:
        size_t          m_size;
        size_t          m_capacity;
        ImageSample     *m_sampleBuffer;
    };

    SampleContainer::SampleContainer(size_t capacity, ImageSample *sampleBuffer)
    : m_size(0)
    , m_capacity(capacity)
    , m_sampleBuffer(sampleBuffer)
    {
        assert(capacity > 0);
        assert(nullptr != sampleBuffer);
    }

    SampleContainer::~SampleContainer() {
        //
    }

    //! \brief  Retrieves the image sample at the specified index within the collection.
    //! \param  index [in] -
    //!         Index of the image sample to be retrieved.
    //! \return The image sample at the specified index.
    const ImageSample& SampleContainer::operator[](size_t index) const {
        assert(index < m_size);
        return m_sampleBuffer[index];
    }


    //! \brief  Retrieves the maximum amount of samples that may be stored within the container instance.
    //! \return The maximum number of samples that may be stored within the container.
    inline size_t SampleContainer::capacity() const {
        return m_capacity;
    }


    //! \brief  Retrieves the current number of samples that are stored within the container.
    //! \return The current number of samples stored within the container.
    inline size_t SampleContainer::size() const {
        return m_size;
    }


    //! \brief  Removes all samples from the container.
    inline void SampleContainer::clear() {
        m_size = 0;
    }


    //! \brief  Attempts to add a new sample to the container.
    //! \param  sample [in] -
    //!         The sample to be added to the container.
    //! \return <em>True</em> if the sample was added successfully otherwise <em>false</em>.
    inline bool SampleContainer::addSample(ImageSample &sample) {
        if ( m_size < m_capacity ) {
            m_sampleBuffer[m_size++] = sample;
            return true;
        }

        return false;
    }

    template <size_t TCapacity >
    class TSampleContainer : public SampleContainer {
    public:
        TSampleContainer();

    private:
        ImageSample     m_samples[TCapacity];
    };

    template <size_t TCapacity>
    TSampleContainer<TCapacity>::TSampleContainer()
    : SampleContainer(TCapacity, m_samples)
    {

    }
}


// -----------------------------------------------------------------------------------

#endif //SAMPLE_CONTAINER_HEADER_INCLUDED
