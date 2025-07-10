void __thiscall __noreturn vostok::engine::engine_world::~engine_world(vostok::engine::engine_world *this)
{
  this->vostok::core::engine::vostok::core::core_debug_engine::vostok::debug::engine::__vftable = (vostok::engine::engine_world_vtbl *)&vostok::engine::engine_world::`vftable'{for `vostok::core::engine'};
  this->vostok::engine_user::engine::__vftable = (vostok::engine_user::engine_vtbl *)&vostok::engine::engine_world::`vftable'{for `vostok::engine_user::engine'};
  this->vostok::editor::engine::__vftable = (vostok::editor::engine_vtbl *)&vostok::engine::engine_world::`vftable'{for `vostok::editor::engine'};
  vostok::engine::engine_world::finalize(this);
}
