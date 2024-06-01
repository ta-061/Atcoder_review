from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.pdfbase import pdfmetrics

# PDFファイルのパス
pdf_path = "summary_reportlab.pdf"
c = canvas.Canvas(pdf_path, pagesize=A4)
width, height = A4

# 日本語フォントの登録
pdfmetrics.registerFont(TTFont('IPAexGothic', '/System/Library/Fonts/ヒラギノ明朝 ProN.ttc'))

# フォント設定
c.setFont("IPAexGothic", 12)

# タイトル
c.drawString(100, height - 50, "応用統計用 A4プリント")

# セクション追加関数
def add_section(title, content, y_pos):
    c.setFont("IPAexGothic", 14)
    c.drawString(30, y_pos, title)
    y_pos -= 20
    c.setFont("IPAexGothic", 12)
    for line in content:
        for subline in line.split('\n'):
            c.drawString(30, y_pos, subline)
            y_pos -= 15
            if y_pos < 50:  # ページが足りなくなったら新しいページを追加
                c.showPage()
                c.setFont("IPAexGothic", 12)
                y_pos = height - 50
    return y_pos

# 用語の意味
y_pos = height - 80
terms_and_meanings = {
    "平均 (Mean)": "データセット内のすべての値の総和をデータの個数で割った値。",
    "標準偏差 (Standard Deviation)": "データのばらつきを示す指標で、データの各値が平均からどれだけ離れているかを示す。",
    "中央値 (Median)": "データを小さい順に並べたときに中央に位置する値。",
    "分散 (Variance)": "データのばらつきを示す指標で、各データが平均からどれだけ離れているかの二乗の平均。"
}
y_pos = add_section("用語の意味", [f"{term}: {meaning}" for term, meaning in terms_and_meanings.items()], y_pos)

# 計算式
c.showPage()
y_pos = height - 50
formulas = {
    "平均の計算式": "Mean = (Σx) / n",
    "標準偏差の計算式": "Standard Deviation = sqrt(Σ(x - Mean)^2 / n)",
    "分散の計算式": "Variance = Σ(x - Mean)^2 / n",
    "中央値の計算式": "Median = Middle value of sorted data"
}
y_pos = add_section("計算式", [f"{name}: {formula}" for name, formula in formulas.items()], y_pos)

# Pythonコード
c.showPage()
y_pos = height - 50
python_codes = [
    {
        "description": "平均と標準偏差の計算",
        "code": """import numpy as np

# データセット
data = [1, 2, 3, 4, 5]

# 平均の計算
mean = np.mean(data)
print("Mean:", mean)

# 標準偏差の計算
std_dev = np.std(data)
print("Standard Deviation:", std_dev)
"""
    },
    {
        "description": "中央値と分散の計算",
        "code": """import numpy as np

# データセット
data = [1, 2, 3, 4, 5]

# 中央値の計算
median = np.median(data)
print("Median:", median)

# 分散の計算
variance = np.var(data)
print("Variance:", variance)
"""
    }
]
for code_info in python_codes:
    y_pos = add_section("Pythonコード", [code_info["description"], code_info["code"]], y_pos)
    c.showPage()
    y_pos = height - 50

# PDF保存
c.save()
