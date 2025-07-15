void __userpurge survarium::hit_info::deserialize(
        survarium::hit_info *this@<ecx>,
        float a2@<xmm0>,
        vostok::network_core::packet_reader *packet)
{
  vostok::network_core::packet_reader *v3; // ecx
  char damage_type_info[16]; // [esp+3Ch] [ebp-20h] BYREF
  char c_body_part_name[16]; // [esp+4Ch] [ebp-10h] BYREF

  this->hit_initiator = vostok::network_core::packet_reader::r<unsigned char>(
                          (vostok::network_core::packet_reader *)this,
                          (int)packet);
  this->being_hit = vostok::network_core::packet_reader::r<unsigned char>(
                      (vostok::network_core::packet_reader *)this,
                      (int)packet);
  vostok::network_core::packet_reader::r_string<16>(v3, (int)packet, (char (*)[16])c_body_part_name);
  vostok::fixed_string<16>::operator=(
    (vostok::fixed_string<16> *)c_body_part_name,
    &this->body_part_name.vostok::buffer_string);
  vostok::network_core::packet_reader::r_string<16>(
    (vostok::network_core::packet_reader *)damage_type_info,
    (int)packet,
    (char (*)[16])damage_type_info);
  vostok::fixed_string<16>::operator=(
    (vostok::fixed_string<16> *)damage_type_info,
    &this->damage_type.vostok::buffer_string);
  vostok::network_core::packet_reader::r<float>(packet);
  this->amount = a2;
  vostok::network_core::packet_reader::r<float>(packet);
  this->armor_piercing = a2;
  this->bullet = 0;
}
