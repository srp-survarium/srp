bool __userpurge survarium::free_fly_camera::on_mouse_key_action@<al>(
        survarium::free_fly_camera *this@<ecx>,
        vostok::input::world *input_world,
        int *button,
        stlp_std::vector<int,survarium::std_allocator<int> > action)
{
  const int *savedregs; // [esp+0h] [ebp+0h]

  if ( action._M_impl._M_start == (int *)2 )
  {
    action._M_impl._M_start = button;
    stlp_std::vector<int,survarium::std_allocator<int>>::push_back(&action, savedregs);
  }
  return 0;
}
