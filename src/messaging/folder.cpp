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

#include "vmime/messaging/folder.hpp"

#include <algorithm>


namespace vmime {
namespace messaging {


void folder::addMessageChangedListener(events::messageChangedListener* l)
{
	m_messageChangedListeners.push_back(l);
}


void folder::removeMessageChangedListener(events::messageChangedListener* l)
{
	std::remove(m_messageChangedListeners.begin(), m_messageChangedListeners.end(), l);
}


void folder::notifyMessageChanged(const events::messageChangedEvent& event)
{
	for (std::list <events::messageChangedListener*>::iterator
	     it = m_messageChangedListeners.begin() ; it != m_messageChangedListeners.end() ; ++it)
	{
		event.dispatch(*it);
	}
}


void folder::addMessageCountListener(events::messageCountListener* l)
{
	m_messageCountListeners.push_back(l);
}


void folder::removeMessageCountListener(events::messageCountListener* l)
{
	std::remove(m_messageCountListeners.begin(), m_messageCountListeners.end(), l);
}


void folder::notifyMessageCount(const events::messageCountEvent& event)
{
	for (std::list <events::messageCountListener*>::iterator
	     it = m_messageCountListeners.begin() ; it != m_messageCountListeners.end() ; ++it)
	{
		event.dispatch(*it);
	}
}


void folder::addFolderListener(events::folderListener* l)
{
	m_folderListeners.push_back(l);
}


void folder::removeFolderListener(events::folderListener* l)
{
	std::remove(m_folderListeners.begin(), m_folderListeners.end(), l);
}


void folder::notifyFolder(const events::folderEvent& event)
{
	for (std::list <events::folderListener*>::iterator
	     it = m_folderListeners.begin() ; it != m_folderListeners.end() ; ++it)
	{
		event.dispatch(*it);
	}
}


} // messaging
} // vmime
