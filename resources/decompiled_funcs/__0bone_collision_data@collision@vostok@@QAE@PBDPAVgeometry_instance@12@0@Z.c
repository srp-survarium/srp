void __userpurge vostok::collision::bone_collision_data::bone_collision_data(
        vostok::collision::bone_collision_data *this@<esi>,
        const char *name@<edx>,
        vostok::collision::geometry_instance *instance,
        const char *part_name)
{
  this->bone_name.m_max_end = (char *)&this->body_part_name;
  this->bone_name.m_begin = this->bone_name.m_buffer;
  this->bone_name.m_end = this->bone_name.m_buffer;
  this->bone_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&this->bone_name, name);
  this->body_part_name.m_begin = this->body_part_name.m_buffer;
  this->body_part_name.m_end = this->body_part_name.m_buffer;
  this->body_part_name.m_max_end = (char *)&this->skeleton_bone_index;
  this->body_part_name.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&this->body_part_name.vostok::buffer_string, part_name);
  this->skeleton_bone_index = -1;
  this->bone_geometry_instance = instance;
}
