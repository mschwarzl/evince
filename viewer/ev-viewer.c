/*
 *  Copyright (C) 2004 Marco Pesenti Gritti
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#include "config.h"

#include "ev-viewer.h"

static void ev_viewer_base_init (gpointer g_class);

GType
ev_viewer_get_type (void)
{
	static GType type = 0;

	if (G_UNLIKELY (type == 0))
	{
		static const GTypeInfo our_info =
		{
			sizeof (EvViewerIface),
			ev_viewer_base_init,
			NULL,
		};

		type = g_type_register_static (G_TYPE_INTERFACE,
					       "EvViewer",
					       &our_info, (GTypeFlags)0);
	}

	return type;
}

static void
ev_viewer_base_init (gpointer g_class)
{
}

void
ev_viewer_load (EvViewer *embed, const char *uri)
{
	EvViewerIface *iface = EV_VIEWER_GET_IFACE (embed);
	iface->load (embed, uri);
}
