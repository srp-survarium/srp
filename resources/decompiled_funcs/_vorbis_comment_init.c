void __cdecl vorbis_comment_init(vorbis_comment *vc)
{
  vc->user_comments = 0;
  vc->comment_lengths = 0;
  vc->comments = 0;
  vc->vendor = 0;
}
