void __thiscall survarium::hit_info::hit_info(
        survarium::hit_info *this,
        unsigned __int8 hit_initiator,
        unsigned __int8 being_hit,
        const char *body_part_name,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  vostok::fixed_string<16>::fixed_string<16>(&this->body_part_name, body_part_name);
  vostok::fixed_string<16>::fixed_string<16>(&this->damage_type, damage_type);
  this->bullet = bullet;
  this->amount = amount;
  this->armor_piercing = armor_piercing;
  this->hit_initiator = hit_initiator;
  this->being_hit = being_hit;
}
