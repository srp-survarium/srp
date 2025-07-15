vostok::render::skeleton_mesh_gpu_skinning_3weights *__thiscall vostok::render::skeleton_mesh_gpu_skinning_3weights::`scalar deleting destructor'(
        vostok::render::skeleton_mesh_gpu_skinning_3weights *this,
        char a2)
{
  vostok::render::skeleton_mesh_gpu_skinning_3weights::~skeleton_mesh_gpu_skinning_3weights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
