//
// VMime library (http://www.vmime.org)
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

#ifndef VMIME_MESSAGEIDSEQUENCE_HPP_INCLUDED
#define VMIME_MESSAGEIDSEQUENCE_HPP_INCLUDED


#include "vmime/messageId.hpp"


namespace vmime
{


/** A list of message identifiers (basic type).
  */

class messageIdSequence : public component
{
public:

	messageIdSequence();
	messageIdSequence(const messageIdSequence& midSeq);

	~messageIdSequence();


	messageIdSequence* clone() const;
	void copyFrom(const component& other);
	messageIdSequence& operator=(const messageIdSequence& other);

	const std::vector <const component*> getChildComponents() const;


	/** Add a message-id at the end of the list.
	  *
	  * @param mid message-id to append
	  */
	void appendMessageId(messageId* mid);

	/** Insert a new message-id before the specified message-id.
	  *
	  * @param beforeMid message-id before which the new message-id will be inserted
	  * @param mid message-id to insert
	  * @throw exceptions::no_such_messageid if the message-id is not in the list
	  */
	void insertMessageIdBefore(messageId* beforeMid, messageId* mid);

	/** Insert a new message-id before the specified position.
	  *
	  * @param pos position at which to insert the new message-id (0 to insert at
	  * the beginning of the list)
	  * @param mid message-id to insert
	  */
	void insertMessageIdBefore(const int pos, messageId* mid);

	/** Insert a new message-id after the specified message-id.
	  *
	  * @param afterMid message-id after which the new message-id will be inserted
	  * @param mid message-id to insert
	  * @throw exceptions::no_such_message_id if the message-id is not in the list
	  */
	void insertMessageIdAfter(messageId* afterMid, messageId* mid);

	/** Insert a new message-id after the specified position.
	  *
	  * @param pos position of the message-id before the new message-id
	  * @param mid message-id to insert
	  */
	void insertMessageIdAfter(const int pos, messageId* mid);

	/** Remove the specified message-id from the list.
	  *
	  * @param mid message-id to remove
	  * @throw exceptions::no_such_message_id if the message-id is not in the list
	  */
	void removeMessageId(messageId* mid);

	/** Remove the message-id at the specified position.
	  *
	  * @param pos position of the message-id to remove
	  */
	void removeMessageId(const int pos);

	/** Remove all message-ids from the list.
	  */
	void removeAllMessageIds();

	/** Return the number of message-ides in the list.
	  *
	  * @return number of message-ides
	  */
	const int getMessageIdCount() const;

	/** Tests whether the list of message-ides is empty.
	  *
	  * @return true if there is no message-id, false otherwise
	  */
	const bool isEmpty() const;

	/** Return the message-id at the specified position.
	  *
	  * @param pos position
	  * @return message-id at position 'pos'
	  */
	messageId* getMessageIdAt(const int pos);

	/** Return the message-id at the specified position.
	  *
	  * @param pos position
	  * @return message-id at position 'pos'
	  */
	const messageId* getMessageIdAt(const int pos) const;

	/** Return the message-id list.
	  *
	  * @return list of message-ids
	  */
	const std::vector <const messageId*> getMessageIdList() const;

	/** Return the message-id list.
	  *
	  * @return list of message-ids
	  */
	const std::vector <messageId*> getMessageIdList();

private:

	std::vector <messageId*> m_list;

public:

	using component::parse;
	using component::generate;

	// Component parsing & assembling
	void parse(const string& buffer, const string::size_type position, const string::size_type end, string::size_type* newPosition = NULL);
	void generate(utility::outputStream& os, const string::size_type maxLineLength = lineLengthLimits::infinite, const string::size_type curLinePos = 0, string::size_type* newLinePos = NULL) const;
};




} // vmime


#endif // VMIME_MESSAGEIDSEQUENCE_HPP_INCLUDED
