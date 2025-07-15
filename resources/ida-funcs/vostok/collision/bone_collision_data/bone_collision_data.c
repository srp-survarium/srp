void __userpurge vostok::collision::bone_collision_data::bone_collision_data(
        vostok::collision::bone_collision_data *this@<ecx>,
        int a2@<edi>,
        char *name,
        char *part_name)
{
  vostok::fixed_string<16> *v4; // ecx

  vostok::fixed_string<64>::fixed_string<64>(&this->bone_name, (vostok::buffer_string *)a2, name);
  vostok::fixed_string<16>::fixed_string<16>(v4, (vostok::buffer_string *)(a2 + 76), part_name);
  *(_DWORD *)(a2 + 104) = -1;
}
