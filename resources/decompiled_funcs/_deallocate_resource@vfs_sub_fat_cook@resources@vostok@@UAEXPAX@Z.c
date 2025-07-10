void __thiscall vostok::resources::vfs_sub_fat_cook::deallocate_resource(
        vostok::resources::vfs_sub_fat_cook *this,
        void *buffer)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  JUMPOUT(0x56FAD);
}
