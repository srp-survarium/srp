vostok::render::skeleton_mesh_gpu_skinning_1weight *__thiscall vostok::render::skeleton_mesh_gpu_skinning_1weight::`vector deleting destructor'(
        vostok::render::skeleton_mesh_gpu_skinning_1weight *this,
        char a2)
{
  vostok::render::skeleton_mesh_gpu_skinning_1weight::~skeleton_mesh_gpu_skinning_1weight(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
