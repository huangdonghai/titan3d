﻿using System;
using System.Collections.Generic;
using System.Text;

namespace EngineNS
{
    [System.ComponentModel.TypeConverterAttribute("System.ComponentModel.ExpandableObjectConverter")]
    public struct RectangleF
    {
        // 考虑到Width、Height有小于0的情况
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Left
        {
            get { return System.Math.Min(X, X + Width); }
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Top
        {
            get { return System.Math.Min(Y, Y + Height); }
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Right
        {
            get { return System.Math.Max(X, X + Width); }
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Bottom
        {
            get { return System.Math.Max(Y, Y + Height); }
        }

        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable | Editor.MacrossMemberAttribute.enMacrossType.NotShowInBreak)]
        public bool IsEmpty
        {
            get
            {
                if (Width == 0 && Height == 0)
                    return true;

                return false;
            }
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable | Editor.MacrossMemberAttribute.enMacrossType.NotShowInBreak)]
        public SizeF Size
        {
            get { return new SizeF(Width, Height); }
            set
            {
                Width = value.Width;
                Height = value.Height;
            }
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable | Editor.MacrossMemberAttribute.enMacrossType.NotShowInBreak)]
        public PointF Location
        {
            get { return new PointF(X, Y); }
            set
            {
                X = value.X;
                Y = value.Y;
            }
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float X
        {
            get;
            set;
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Y
        {
            get;
            set;
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Width
        {
            get;
            set;
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public float Height
        {
            get;
            set;
        }

        static RectangleF mEmpty = new RectangleF(0, 0, 0, 0);
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable | Editor.MacrossMemberAttribute.enMacrossType.NotShowInBreak)]
        public static RectangleF Empty
        {
            get { return mEmpty; }
        }
        static RectangleF mInfinity = new RectangleF(0, 0, float.PositiveInfinity, float.PositiveInfinity);
        public static RectangleF Infinity => mInfinity;

        public RectangleF(float x, float y, float width, float height)
        {
            X = x;
            Y = y;
            Width = width;
            Height = height;
        }

        public RectangleF(PointF pt, SizeF size)
        {
            X = pt.X;
            Y = pt.Y;
            Width = size.Width;
            Height = size.Height;
        }
        public bool Contains(ref PointF pt)
        {
            if ((pt.X >= Left) && (pt.Y >= Top) && (pt.X < Right) && (pt.Y < Bottom))
                return true;

            return false;
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public bool Contains(PointF pt)
        {
            return Contains(ref pt);
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public bool Contains(float x, float y)
        {
            if ((x >= Left) && (y >= Top) && (x < Right) && (y < Bottom))
                return true;

            return false;
        }

        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public static RectangleF Intersect( RectangleF a, RectangleF b )
        {
            return Intersect(ref a, ref b);
        }
        public static RectangleF Intersect(ref RectangleF a, ref RectangleF b)
        {
            if (a.Left > b.Right || a.Top > b.Bottom || a.Right < b.Left || a.Bottom < b.Top)
                return RectangleF.Empty;

            var left = System.Math.Max(a.Left, b.Left);
            var top = System.Math.Max(a.Top, b.Top);
            var right = System.Math.Min(a.Right, b.Right);
            var bottom = System.Math.Min(a.Bottom, b.Bottom);

            return new RectangleF(left, top, right - left, bottom - top);
        }
        [Editor.MacrossMember(Editor.MacrossMemberAttribute.enMacrossType.Callable)]
        public RectangleF Intersect(ref RectangleF rect)
        {
            return Intersect(ref this, ref rect);
        }

        public override bool Equals(object obj)
        {
            var tag = (RectangleF)obj;
            if ((System.Math.Abs(X - tag.X) <= CoreDefine.Epsilon) &&
                (System.Math.Abs(Y - tag.Y) <= CoreDefine.Epsilon) &&
                (System.Math.Abs(Width - tag.Width) <= CoreDefine.Epsilon) &&
                (System.Math.Abs(Height - tag.Height) <= CoreDefine.Epsilon))
                return true;
            return false;
        }
        public bool Equals(ref RectangleF tag)
        {
            if ((System.Math.Abs(X - tag.X) <= CoreDefine.Epsilon) &&
                (System.Math.Abs(Y - tag.Y) <= CoreDefine.Epsilon) &&
                (System.Math.Abs(Width - tag.Width) <= CoreDefine.Epsilon) &&
                (System.Math.Abs(Height - tag.Height) <= CoreDefine.Epsilon))
                return true;
            return false;
        }

        public override int GetHashCode()
        {
            //return (int)(X + Y + Width + Height);
            return base.GetHashCode();
        }
    }
}
