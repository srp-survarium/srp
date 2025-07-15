vostok::render::skeleton_mesh_gpu_skinning_2weights *__thiscall vostok::render::skeleton_mesh_gpu_skinning_2weights::`scalar deleting destructor'(
        vostok::render::skeleton_mesh_gpu_skinning_2weights *this,
        char a2)
{
  vostok::render::skeleton_mesh_gpu_skinning_2weights::~skeleton_mesh_gpu_skinning_2weights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
