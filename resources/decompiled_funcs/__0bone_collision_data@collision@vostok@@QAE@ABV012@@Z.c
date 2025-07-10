void __usercall vostok::collision::bone_collision_data::bone_collision_data(
        vostok::collision::bone_collision_data *this@<esi>,
        const vostok::collision::bone_collision_data *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  char *v5; // edx
  char *v6; // ecx
  char *v7; // ebx

  m_begin = (unsigned __int8 *)__that->bone_name.m_begin;
  v3 = __that->bone_name.m_end - __that->bone_name.m_begin;
  this->bone_name.m_max_end = (char *)&this->body_part_name;
  v4 = v3;
  this->bone_name.m_begin = this->bone_name.m_buffer;
  this->bone_name.m_end = this->bone_name.m_buffer;
  memcpy((unsigned __int8 *)this->bone_name.m_buffer, m_begin, v3);
  this->bone_name.m_end += v4;
  *this->bone_name.m_end = 0;
  v5 = __that->body_part_name.m_begin;
  v6 = (char *)(__that->body_part_name.m_end - v5);
  this->body_part_name.m_max_end = (char *)&this->skeleton_bone_index;
  v7 = v6;
  this->body_part_name.m_begin = this->body_part_name.m_buffer;
  this->body_part_name.m_end = this->body_part_name.m_buffer;
  memcpy((unsigned __int8 *)this->body_part_name.m_buffer, (unsigned __int8 *)v5, (unsigned int)v6);
  this->body_part_name.m_end += (unsigned int)v7;
  *this->body_part_name.m_end = 0;
  this->skeleton_bone_index = __that->skeleton_bone_index;
  this->bone_geometry_instance = __that->bone_geometry_instance;
}
