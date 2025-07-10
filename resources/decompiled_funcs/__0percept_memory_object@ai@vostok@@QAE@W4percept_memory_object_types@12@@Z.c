void __userpurge vostok::ai::percept_memory_object::percept_memory_object(
        vostok::ai::percept_memory_object *this@<ecx>,
        float other_x@<xmm0>,
        vostok::ai::percept_memory_object_types knowledge_type)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->object = 0;
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::math::float3::float3(&this->owner_position, LODWORD(other_x), LODWORD(other_x), other_x);
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::math::float3::float3(&this->target_position, LODWORD(other_x), LODWORD(other_x), other_x);
  this->update_time = vostok::memory::uninitialized_value<unsigned int>();
  this->type = knowledge_type;
  this->confidence = *(float *)&FLOAT_0_0;
  this->next = 0;
}
