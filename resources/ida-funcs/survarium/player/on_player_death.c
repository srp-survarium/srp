void __thiscall survarium::player::on_player_death(
        survarium::player *this,
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *current_time_in_ms)
{
  int v3; // eax

  survarium::base_player::on_player_death(this, current_time_in_ms);
  v3 = *(int *)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
              + (_DWORD)&loc_11403
              + 5);
  if ( v3 )
    *(_DWORD *)(v3 + 684) = *(_DWORD *)(v3 + 680);
}
