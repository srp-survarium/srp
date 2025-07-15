void __thiscall thread_dispatch_callbacks(vostok::command_line::key *this)
{
  vostok::tasks *v1; // ecx

  while ( !s_resources_callbacks_have_been_dispatched )
  {
    vostok::resources::dispatch_callbacks(this);
    vostok::threading::yield(0, v1);
  }
  vostok::resources::dispatch_callbacks(this);
}
