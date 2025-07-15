void __thiscall dynamic_initializer_for__s_no_warning_on_page_file_size__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &s_no_warning_on_page_file_size,
    "no_warning_on_page_file_size",
    uri,
    "memory",
    "suppress warning about too many programs open or not enough page file size",
    uri);
}
