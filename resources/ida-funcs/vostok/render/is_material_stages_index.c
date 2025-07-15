bool __usercall vostok::render::is_material_stages_index@<al>(unsigned int stage_index@<eax>)
{
  return stage_index <= 3
      || stage_index > 0xF && (stage_index <= 0x11 || stage_index == 24 || stage_index > 0x19 && stage_index <= 0x1B);
}
