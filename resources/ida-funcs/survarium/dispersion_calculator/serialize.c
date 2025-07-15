void __userpurge survarium::dispersion_calculator::serialize(
        survarium::dispersion_calculator *this@<ecx>,
        int a2@<esi>,
        vostok::network_core::buffer_writer *writer,
        int time_offset)
{
  survarium::transition_helper *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx

  survarium::transition_helper::serialize((survarium::transition_helper *)this, a2 + 12, writer, time_offset);
  survarium::transition_helper::serialize(v4, a2 + 32, writer, time_offset);
  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 52),
    v5,
    writer,
    ".\\dispersion_calculator.cpp",
    (const char *)0x86,
    "survarium::dispersion_calculator::serialize",
    "m_skill_influence");
}
