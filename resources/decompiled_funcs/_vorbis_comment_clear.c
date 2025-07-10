void __usercall vorbis_comment_clear(
        vostok::memory::doug_lea_mt_allocator *a1@<ecx>,
        vostok::memory *a2@<ebx>,
        vostok::memory *a3@<edi>,
        vorbis_comment *vc)
{
  int v4; // edi
  char *v5; // ebx
  char **user_comments; // edi
  int *comment_lengths; // edi
  char *vendor; // edi
  vostok::memory *v9; // [esp-8h] [ebp-Ch]
  vostok::memory *v10; // [esp-4h] [ebp-8h]

  if ( vc )
  {
    v10 = a3;
    if ( vc->user_comments )
    {
      v4 = 0;
      if ( vc->comments > 0 )
      {
        v9 = a2;
        do
        {
          if ( vc->user_comments[v4] )
          {
            v5 = vc->user_comments[v4];
            if ( !vostok::memory::g_crt_allocator.__vftable )
              vostok::memory::initialize_crt_allocator(v9);
            vostok::memory::doug_lea_mt_allocator::free_impl(a1, v5);
          }
          ++v4;
        }
        while ( v4 < vc->comments );
      }
      user_comments = vc->user_comments;
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v10);
      vostok::memory::doug_lea_mt_allocator::free_impl(a1, user_comments);
    }
    comment_lengths = vc->comment_lengths;
    if ( comment_lengths )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v10);
      vostok::memory::doug_lea_mt_allocator::free_impl(a1, comment_lengths);
    }
    vendor = vc->vendor;
    if ( vendor )
    {
      if ( !vostok::memory::g_crt_allocator.__vftable )
        vostok::memory::initialize_crt_allocator(v10);
      vostok::memory::doug_lea_mt_allocator::free_impl(a1, vendor);
    }
    vc->user_comments = 0;
    vc->comment_lengths = 0;
    vc->comments = 0;
    vc->vendor = 0;
  }
}
