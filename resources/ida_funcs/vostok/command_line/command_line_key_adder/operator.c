void __usercall vostok::command_line::command_line_key_adder::operator()(
        vostok::command_line::command_line_key_adder *this@<eax>,
        vostok::command_line::key *const command_line_key@<edi>)
{
  vostok::buffer_vector<vostok::command_line::key *> *keys; // esi
  vostok::command_line::key **m_end; // eax

  this->longest_short_key_name = vostok::math::max(this->longest_short_key_name, strlen(command_line_key->m_short_name));
  this->longest_full_key_name = vostok::math::max(this->longest_full_key_name, strlen(command_line_key->m_full_name));
  keys = this->keys_;
  m_end = keys->m_end;
  if ( m_end )
    *m_end = command_line_key;
  ++keys->m_end;
}
