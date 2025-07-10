void __usercall vostok::render::skeleton_mesh_gpu_skinning_1weight::skeleton_mesh_gpu_skinning_1weight(
        vostok::render::skeleton_mesh_gpu_skinning_1weight *this@<ecx>,
        unsigned int **a2@<esi>)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  a2[1] = (unsigned int *)3;
  *a2 = &stru_966A14.m_desc_3d.CPUAccessFlags;
  a2[39] = 0;
}
