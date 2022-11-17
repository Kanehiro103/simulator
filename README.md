# simulator
CPU実験2022の1班用シミュレータです。

ビルド:

% make

使用方法：

1. samples以下に機械語コード "filename.dat" を追加(fib.dat参照)

2. 以下のコマンドを実行で標準出力にレジスタの最終状態を表示

% ./test filename

注意事項等:

1. 実行終了は無限ループを想定

2. logfiles以下に"log_filename.dat"が生成されます
