const char *__usercall vostok::render::stage_type_to_string@<eax>(int stage_type@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  if ( stage_type <= 16 )
  {
    if ( stage_type == 16 )
      return "forward";
    v1 = stage_type - 1;
    if ( !v1 )
      return "g_stage";
    v2 = v1 - 1;
    if ( !v2 )
      return "decals";
    v3 = v2 - 1;
    if ( !v3 )
      return "distortion";
    v4 = v3 - 2;
    if ( !v4 )
      return "ambient_occlusion";
    if ( v4 == 3 )
      return "light_propagation_volumes";
    return 0;
  }
  v6 = stage_type - 17;
  if ( !v6 )
    return "lighting";
  v7 = v6 - 7;
  if ( !v7 )
    return "post_process";
  v8 = v7 - 1;
  if ( !v8 )
    return "debug_post_process";
  v9 = v8 - 1;
  if ( !v9 )
    return (const char *)&stru_802CB8;
  if ( v9 != 1 )
    return 0;
  return "shadow";
}
