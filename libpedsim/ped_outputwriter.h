//
// pedsim - A microscopic pedestrian simulation system.
// Copyright (c) 2003 - 2014 by Christian Gloor
//

#ifndef _ped_outputwriter_h_
#define _ped_outputwriter_h_ 1

#ifdef WIN32
#define LIBEXPORT __declspec(dllexport)
#else
#define LIBEXPORT
#endif

#include <iostream>
#include <fstream>

#include "ped_includes.h"

namespace Ped {

    /// Abstract Base Class that defines a Toutputwriter interface/default implementation.
    /// \author  chgloor
    /// \date    2014-12-18
    class LIBEXPORT OutputWriter {
    public:
        virtual ~OutputWriter() {};

        // pure virtual functions providing the framework.

	// general
	virtual void writeTimeStep(long int timestep) = 0;

        // szene
        virtual void defineScene(Tscene &s) = 0;
        virtual void addObstacle(Tobstacle &o) = 0;
        virtual void addAgent(Tagent &a) = 0;

        // agent
        virtual void drawAgent(Tagent &a) = 0;

    protected:
    };


    /// Class that defines a simple CSV OutputWriter
    /// \author  chgloor
    /// \date    2014-12-19
    class LIBEXPORT CSV_OutputWriter : public OutputWriter {
    public:
        virtual ~CSV_OutputWriter() {};

	// general
	virtual void writeTimeStep(long int timestep) {};

        // szene
        virtual void defineScene(Tscene &s) {};
        virtual void addObstacle(Tobstacle &o) {};
        virtual void addAgent(Tagent &a) {};

        // agent
        virtual void drawAgent(Tagent &a) { cout << a.getid() << ", " << a.getx() << ", " << a.gety() << endl; };

    protected:
    };


    /// Class that defines a frame-by-frame proprietary OutputWriter
    /// \author  chgloor
    /// \date    2016-07-02
    class LIBEXPORT Frame_OutputWriter : public OutputWriter {
    public:
        Frame_OutputWriter();
        Frame_OutputWriter(string name);
        virtual ~Frame_OutputWriter();

	// general
	virtual void writeTimeStep(long int timestep);

        // szene
        virtual void defineScene(Tscene &s) {};
        virtual void addObstacle(Tobstacle &o) {};
        virtual void addAgent(Tagent &a) {};

        // agent
        virtual void drawAgent(Tagent &a);

    protected:
	ofstream outfile;
    };


}

#endif