const char *__usercall vostok::render::stage_type_to_string@<eax>(
        vostok::render::enum_render_stage_type stage_type@<eax>)
{
  const char *result; // eax

  switch ( stage_type )
  {
    case gbuffer_render_stage:
      result = (const char *)&stru_960978;
      break;
    case decals_accumulate_render_stage:
      result = "decals";
      break;
    case accumulate_distortion_render_stage:
      result = "distortion";
      break;
    case ambient_occlusion_render_stage:
      result = "ambient_occlusion";
      break;
    case light_propagation_volumes_render_stage:
      result = "light_propagation_volumes";
      break;
    case forward_render_stage:
      result = "forward";
      break;
    case lighting_render_stage:
      result = (const char *)&stru_960A90.type;
      break;
    case post_process_render_stage:
      result = (const char *)&stru_95F7AC;
      break;
    case debug_post_process_render_stage:
      result = "debug_post_process";
      break;
    case debug_render_stage:
      result = "debug";
      break;
    case shadow_render_stage:
      result = "shadow";
      break;
    default:
      result = "unknown";
      break;
  }
  return result;
}
