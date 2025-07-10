void __usercall vostok::ui::client_to_screen(
        const vostok::ui::ui_window *w@<ecx>,
        vostok::math::float2 *src_and_dest@<edi>)
{
  vostok::ui::window *i; // esi
  float *v3; // eax
  vostok::ui::window *(__thiscall *get_parent)(vostok::ui::window *); // edx

  for ( i = w->get_parent(w); i; i = get_parent(i) )
  {
    v3 = (float *)i->get_position(i);
    src_and_dest->x = *v3 + src_and_dest->x;
    get_parent = i->get_parent;
    src_and_dest->y = v3[1] + src_and_dest->y;
  }
}
