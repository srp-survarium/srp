void __thiscall survarium::hit_info::hit_info(survarium::hit_info *this)
{
  vostok::fixed_string<16> *v1; // ecx

  vostok::fixed_string<16>::fixed_string<16>(&this->body_part_name, (int)this);
  vostok::fixed_string<16>::fixed_string<16>(v1, (int)&this->damage_type);
}
