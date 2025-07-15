vostok::render::skeleton_mesh_gpu_skinning_4weights *__thiscall vostok::render::skeleton_mesh_gpu_skinning_4weights::`vector deleting destructor'(
        vostok::render::skeleton_mesh_gpu_skinning_4weights *this,
        char a2)
{
  vostok::render::skeleton_mesh_gpu_skinning_4weights::~skeleton_mesh_gpu_skinning_4weights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
