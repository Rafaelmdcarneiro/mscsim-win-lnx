/****************************************************************************//*
 * Copyright (C) 2021 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/

#include <cgi/otw/cgi_Entities.h>

#include <cgi/cgi_Models.h>
#include <cgi/cgi_WGS84.h>

#include <cgi/otw/cgi_Reflection.h>

////////////////////////////////////////////////////////////////////////////////

using namespace cgi;

////////////////////////////////////////////////////////////////////////////////

Entities::Entities( const Module *parent ) :
    Module( parent )
{
    _patLCS = new osg::PositionAttitudeTransform();
    _patCVN = new osg::PositionAttitudeTransform();

    _root->addChild( _patLCS.get() );
    _root->addChild( _patCVN.get() );

    addEntity( _patLCS.get(), "cgi/entities/lcs.osgb"  );
    //addEntity( _patCVN.get(), "cgi/entities/cvn.osgb" );

    WGS84::setLatLonAltHdg( _patLCS.get(), osg::DegreesToRadians( 21.3529540 ), osg::DegreesToRadians( -157.9685000 ), 0.0, osg::DegreesToRadians( 180.0 ) );
}

////////////////////////////////////////////////////////////////////////////////

Entities::~Entities() {}

////////////////////////////////////////////////////////////////////////////////

void Entities::update()
{
    /////////////////
    Module::update();
    /////////////////
}

////////////////////////////////////////////////////////////////////////////////

void Entities::addEntity( osg::PositionAttitudeTransform *pat, const char *file )
{
    osg::ref_ptr<osg::Node> node = Models::get( file );

    if ( node.valid() )
    {
        pat->addChild( node.get() );

        Reflection::create( node.get(), pat );
    }
}
