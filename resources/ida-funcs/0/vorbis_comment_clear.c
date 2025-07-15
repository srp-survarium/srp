void __cdecl vorbis_comment_clear(vorbis_comment *vc)
{
  int i; // esi
  void **v2; // eax

  if ( vc )
  {
    if ( vc->user_comments )
    {
      for ( i = 0; i < vc->comments; ++i )
      {
        v2 = (void **)&vc->user_comments[i];
        if ( *v2 )
          ogg_free_impl(*v2);
      }
      ogg_free_impl(vc->user_comments);
    }
    if ( vc->comment_lengths )
      ogg_free_impl(vc->comment_lengths);
    if ( vc->vendor )
      ogg_free_impl(vc->vendor);
    vc->user_comments = 0;
    vc->comment_lengths = 0;
    vc->comments = 0;
    vc->vendor = 0;
  }
}
