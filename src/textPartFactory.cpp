//
// VMime library (http://vmime.sourceforge.net)
// Copyright (C) 2002-2005 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#include "vmime/textPartFactory.hpp"
#include "vmime/exception.hpp"


#include "vmime/plainTextPart.hpp"
#include "vmime/htmlTextPart.hpp"


namespace vmime
{


textPartFactory::textPartFactory()
{
	// Register some default names
	registerType <plainTextPart>(mediaType(mediaTypes::TEXT, mediaTypes::TEXT_PLAIN));
	registerType <htmlTextPart>(mediaType(mediaTypes::TEXT, mediaTypes::TEXT_HTML));
}


textPartFactory::~textPartFactory()
{
}


textPart* textPartFactory::create(const mediaType& type)
{
	NameMap::const_iterator pos = m_nameMap.find(type.generate());

	if (pos != m_nameMap.end())
	{
		return ((*pos).second)();
	}
	else
	{
		throw exceptions::no_factory_available();
	}
}


} // vmime
