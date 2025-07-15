void __thiscall survarium::bullet_manager::set_max_bullets(survarium::bullet_manager *this, char *args)
{
  int new_bullets_count; // [esp+4h] [ebp-4h] BYREF

  if ( sscanf_s(args, "%d", &new_bullets_count) != -1 )
    survarium::bullet_manager::allocate_bullets_memory(this, new_bullets_count);
}
