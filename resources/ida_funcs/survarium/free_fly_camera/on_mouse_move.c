bool __thiscall survarium::free_fly_camera::on_mouse_move(
        survarium::free_fly_camera *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  this->m_inverted_view_matrix.k.y = (float)((float)((float)x * 0.0055555557) * 3.1415927)
                                   + this->m_inverted_view_matrix.k.y;
  this->m_inverted_view_matrix.k.z = (float)((float)((float)y * 0.0055555557) * 3.1415927)
                                   + this->m_inverted_view_matrix.k.z;
  this->m_inverted_view_matrix.k.w = (float)((float)((float)z * 0.0055555557) * 3.1415927)
                                   + this->m_inverted_view_matrix.k.w;
  return 0;
}
