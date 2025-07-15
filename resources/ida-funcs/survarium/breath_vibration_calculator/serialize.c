void __userpurge survarium::breath_vibration_calculator::serialize(
        survarium::breath_vibration_calculator *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        const unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::ai::fsm *v11; // ecx

  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 64),
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\breath_vibration_calculator.cpp",
    (const char *)0x91,
    "survarium::breath_vibration_calculator::serialize",
    "m_phase_time");
  vostok::network_core::buffer_writer::w<vostok::math::float2>(
    (vostok::math::float2 *)(a2 + 68),
    v6,
    writer,
    ".\\breath_vibration_calculator.cpp",
    (const char *)0x92,
    "survarium::breath_vibration_calculator::serialize",
    "m_vibration");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 76),
    v7,
    writer,
    ".\\breath_vibration_calculator.cpp",
    (const char *)0x93,
    "survarium::breath_vibration_calculator::serialize",
    "m_amplitude");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 80),
    v8,
    writer,
    ".\\breath_vibration_calculator.cpp",
    (const char *)0x94,
    "survarium::breath_vibration_calculator::serialize",
    "m_breath_holding_reserve");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 84),
    v9,
    writer,
    ".\\breath_vibration_calculator.cpp",
    (const char *)0x95,
    "survarium::breath_vibration_calculator::serialize",
    "m_speed_factor");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 88),
    v10,
    writer,
    ".\\breath_vibration_calculator.cpp",
    (const char *)0x96,
    "survarium::breath_vibration_calculator::serialize",
    "m_penalty_factor");
  vostok::ai::fsm::serialize(v11, a2, writer, client_writer);
}
